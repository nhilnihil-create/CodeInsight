
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, m;
    cin >> n >> m;
    int ac=0;
    vector<int> watemp(n,0);
    int wa=0;
    vector<int> isok(n,0);

    for(int i=0; i<m; i++){
        int p;
        string s;
        cin >> p >> s;
        //初めて正解した場合
        if(isok.at(p-1) == 0 && s == "AC"){
            ac ++;
            isok.at(p-1) = 1;
            //正解前にWAを出していたらペナルティを追加
            if(watemp.at(p-1) != 0){
                wa += watemp.at(p-1);
            }
        }
        //AC前の問題でWAを出した場合
        else if(isok.at(p-1) == 0 && s == "WA"){
            watemp.at(p-1) ++;
        }
        else continue;
    }
    cout << ac << " " << wa << endl;

}