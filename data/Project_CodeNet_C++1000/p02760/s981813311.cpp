#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 100005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll,ll>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define endl "\n"
using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}

int dp[1003];
bool check;
int arr[3][3];

void row(int i) {
    int cnt = 0;

    for(int j=0; j<3; j++) {
        cnt+= dp[arr[i][j]];
    }

    if(cnt == 3) {
        check = true;
    }
}

void col(int j) {
    int cnt = 0;

    for(int i=0; i<3; i++) {
        cnt+= dp[arr[i][j]];
    }

    if(cnt == 3) {
        check = true;
    }
}



void test_case() {

    

    rep(i,3) {
        rep(j,3) {
            cin>>arr[i][j];
        }
    }

    int n;
    cin>>n;

    check = false;

    rep(i,n) {
        int x;
        cin>>x;

        dp[x] = 1;
    }


    rep(i,3) {
        row(i);
        col(i);
    }


    int cnt = 0;
    for(int i=0; i<3; i++) {
        cnt+= dp[arr[i][i]];
    }

    if(cnt == 3) {
        check = true;
    }

    cnt=0;
    for(int j=2; j>=0; j--) {
        cnt+= dp[arr[2-j][j]];
    }

    if(cnt == 3) {
        check = true;
    }

    if(check) {
        yes;
    } else {
        no;
    }
    




    



}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);

    //    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int t = 1;
   //  cin >> t;
    while(t--)
    {   
        test_case();
    }
}
