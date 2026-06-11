#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<P> input;
    rep0(i,M){
        P p;
        cin >> p.first >> p.second;
        input.push_back(p);
    }
    string res ="";
    rep0(i,N){
        res+="a";
    }
    rep0(i,M){
        if(res[input[i].first-1]!='a'&&res[input[i].first-1]!=(char)(input[i].second+'1'-1)){
            cout << -1 << endl;
            return 0;
        }
        res[input[i].first-1]=(char)(input[i].second+'1'-1);
    }
    rep0(i,N){
        if(res[i]=='a'){
            if(i==0&&N!=1){
                res[i]='1';
            }else{
                res[i] = '0';
            }
        }
    }
    if(res[0]=='0'&&N!=1){
        cout << -1 << endl;        
        return 0;
    }
    cout <<res<<endl;

}
