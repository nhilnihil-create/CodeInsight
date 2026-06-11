#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int N;
    cin >> N;
    vector<int> L(N);
    rep(i, N) cin >> L.at(i);
    sort(all(L));

    int a, b, c, flag=0, ans=0;
    map<int, vector<int>> cont;
    vector<int> new_vec;

    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                a = L.at(i);
                b = L.at(j);
                c = L.at(k);
                if(c < a+b && a != b && b != c && a != c){
                    ans++;
                    /*
                    new_vec = {a, b, c};        
                    flag=0;
                    rep(tmp, cont.size()){
                        if(cont.at(tmp)==new_vec){
                            flag=1;
                        }
                    }
                    if(flag==0){
                        cont[cont.size()] = new_vec;
                    }
                    */
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}