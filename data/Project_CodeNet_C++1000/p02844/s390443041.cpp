#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793238462643383279
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;


string moji(int i,int j,int k){
    string s;
    s += to_string(i)+to_string(j)+to_string(k);
    return s;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;

   for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
           for(int k = 0; k < 10; k++){
               string a = moji(i,j,k);

                int index = 0;
                for(int i = 0; i < s.size(); i++){
                    if(s[i] == a[index]){
                        index++;
                    }
                    if(index == a.size()){
                        cnt++;
                        break;
                    }
                }
           }
       }
   }

    cout << cnt << endl;

    



}