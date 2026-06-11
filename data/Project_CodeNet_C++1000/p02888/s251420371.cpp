  #include <bits/stdc++.h>
  using namespace std;

  #define vi vector<int>
  #define all(v) v.begin(),v.end()
  #define ll long long int
  #define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define D1(x) {cerr<<" [" <<#x<<": "<<x<<"]";cout << endl;}
  #define D2(x) {cerr<<" [" <<#x<<": ";for(auto it:x)cerr<<it<< " ";cerr<<"] ";cout << endl;}

  const ll MOD=1e9+7;

  void solve(){
     int n;
     cin >> n;
     vi v(n);
     for(int i=0;i<n;i++)cin >> v[i];
     sort(all(v));
     int ans =0;
    //  1 2 3 4
    //  1 2 3 4
    //  ^ ^
    D2(v);
     for(int j=n-1;j>=2;j--){
       int i=0,k=j-1;
       while(i<k){
          while(i<k && v[i]+v[k]>v[j])k--;
          ans += (j-k-1);
          i++;
       }
       int o = j-i;
       ans += max(0,(o*(o-1))/2);

     }
     cout << ans;
  }


  int main(){
    IOS
       solve();
       cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
