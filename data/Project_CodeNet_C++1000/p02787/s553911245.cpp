#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo for(int i=0;i<n;i++)
#define clear cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define loopSolve int t; cin>>t; while(t--){solve();}
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

//INT_MAX         2,147,483,647                       <10^10
//U_INT_MAX       4,294,967,295                       <10^10
//LONG_LONG_MAX   9,223,372,036,854,775,807           <10^18
//U_LONG_LONG_MAX 18,446,744,073,709,551,615          <10^18
//ll power(int a, int b){
//    return (ll)(pow(a,b)+0.5);
//}

vector<int> gV(int n){
    vector<int> v(n);
    fo { cin>>v[i];  }
    return v;
}

int* gA(int n){
    int* arr = new int[n];
    fo cin>>arr[i];
    return arr;
}


void solve(){
    int c,n;
    cin>>c>>n;
    static ll dp[1001][20001];
    ll wt[1001]; ll val[1001];

    for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];

//    for(int i=0;i<n;i++)
//        cout<<wt[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<n;i++)
//        cout<<val[i]<<" ";
//    cout<<endl;

    for(int i=0;i<=2*c;i++)
        dp[0][i]=INT_MAX-2000;
    for(int i=0;i<=n;i++)
        dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*c;j++){
            if(wt[i-1]<=j){
                dp[i][j]= min(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=min(dp[i-1][j],val[i-1]);
                //dp[i][j]=dp[i-1][j];
            }
        }
    }

//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=c;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }

    int m=c+1;
    while(m<=2*c && dp[n][c]==INT_MAX-2000){
        dp[n][c]=min(dp[n][c],dp[n][m]);
        m++;
    }
    cout<<dp[n][c]<<endl;


}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}
