   #include<bits/stdc++.h>
   #include<algorithm>


#define endl '\n'
#define all(v) v.begin(), v.end()
#define intvect vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define boolv vector<bool>
#define ld long double
#define deb(x) cout << #x << " " << x << endl;
#define pb push_back
#define pob pop_back
#define F first
#define S second
#define ub upper_bound
#define bs binary_search
#define lb lower_bound
#define ull unsigned long long

        typedef unsigned long long int ll ;
        using namespace std;




int main(){
    ll n, i, flag = 0;
   cin >> n;
int x[n], y[n];
  fo(i, n) cin >> x[i] >> y[i];
  for(i=0; i<n-2; i++){
    if((x[i] == y[i] && x[i+1] == y[i+1]) && (x[i+2]==y[i+2])) flag = 1;
  }
if(flag) cout << "Yes";
else cout << "No";
}
