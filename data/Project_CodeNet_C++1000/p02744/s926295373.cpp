#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);
int n;

void dfs(string s,char mx){
    if(s.size() == n){
        cout << s << endl;
        return;
    }else if(s.size() == 0){
        s = "a";
        dfs(s,'a');
    }
    else
    {
        char nx = char(int(mx) + 1);
        for(char c = 'a';c<=nx;c++){
            if(c == nx){
                dfs(s+c,nx);
            }else{
                dfs(s+c,mx);
            }
        }
    }
}


int main(){
    cin >> n;
    dfs("",'a');
    return 0;

}