#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 5e3+1;

vector<ll> weight(MAX);
vector<ll> position(MAX);
vector<ll> prefix_sum;
bool visited[MAX];

void pre_process(ll i, ll sum){

    if(visited[i] == true) return;

    visited[i] = true;

    sum =  sum + weight[i];
    prefix_sum.push_back(sum);

    pre_process(position[i], sum);
}

void solve(){

    int N, K; cin>>N>>K;

    for (int i=1; i<=N; i++)
        cin>>position[i];

    for (int i=1; i<=N; i++)
        cin>>weight[i];

    ll total_maximum = LONG_MIN;

    for (int i = 1; i<=N; i++){

        memset(visited, false, sizeof(visited));
        pre_process(i, 0);

        /*
            Sendo que o número de elementos a cada query pode não ser igual a "N", então:
            Número de elemento a cada query = Elementos visitados.

            Se todos os elementos forem positivos, quer dizer que está fofo. Quanto mais iterar, melhor será a maximização.
        */

        if(prefix_sum.back()>0 && K>=(int)prefix_sum.size()){

            /*
                Se K >= Tamanho de elementos em qualquer query, então:
                Número de rotações = K/Número de elementos visitados.

                Para houver rotação:
                    - K deve ser maior que o número de elementos visitados
                    - Último elemento deve ser maior que zero senão, a resposta estará na primeira consulta.

                Se houver rotação:
                    - Itera-se todo o prefix_sum em funcão do número de cíclos;
                    - Pegando o módulo, itera-se o resto.
            */
            int rotations = (int) (K/(int)prefix_sum.size());

            /*Para não houver redundância em termos de rotação, o último elemento a ser visitado "n" vezes, vale:
                Último elemento elemento = K%Número de elementos de cada query.
            */
            int last_index = (int) (K%(int)prefix_sum.size());

            ll maximum = LONG_MIN;
            for (int j=1; j<=(int)prefix_sum.size(); j++)
                maximum = max(maximum, prefix_sum[j-1]);

            total_maximum = max(total_maximum, ((rotations-1)*prefix_sum.back()) + maximum);

            /*Nem sempre a última soma é a melhor. Porém, há necessidade de se verificar
                o máximo duas vezes. Existirá casos, em que a melhor soma estará infiltrado entre as posições do prefix_sum.
            */

            maximum = LONG_MIN;
            for (int j=1; j<=(int)last_index; j++)
                maximum = max(maximum, prefix_sum[j-1]);

            total_maximum = max(total_maximum, (rotations*prefix_sum.back()) + maximum);
        } else{

            //Será executado quando não é necessário fazer rotações.

            for (int j = 1; j<=min((int)prefix_sum.size(), K); j++)
                total_maximum = max(total_maximum, prefix_sum[j-1]);
        }

        prefix_sum.clear();
    }

    cout<<total_maximum<<endl;

}

int main()
{
    solve();
    return 0;
}
