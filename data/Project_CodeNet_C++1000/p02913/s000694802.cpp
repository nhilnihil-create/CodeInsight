#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1e15;
const int MOD = 1000000007;



int main(){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for(int i=0;i<n;i++){
                string now = s.substr(i);
                //cout << now << endl;
                vector<int> a(n-i,0);
                int c = 0;
                for(int j=1;j<now.size();j++){
                        if(j + a[j-c] < c + a[c]){
                                a[j] = a[j-c];
                        }
                        else{
                                int k = max(0,c+a[c]-j);
                                while(j+k < now.size() && now[k] == now[j+k]) k ++;
                                a[j] = k;
                                c = j;
                        }
                        int res = min(a[j],j);
                        ans = max(ans,res);
                }
        }
        cout << ans << endl;
    

        return 0;
}




