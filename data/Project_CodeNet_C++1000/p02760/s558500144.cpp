//g++ -std=c++17 -Wall t.cpp -o test -g -O2
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define teto(a, b) (a+b-1)/(b)
 
const int MAX = 1000010;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-6;
const ld PI = acos(-1.0);

using namespace std;

// End - Template //

int num[1000]={0};
int mat[3][3];
int main()
{sws;
    
    int n, a;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> mat[i][j];
        
    cin >> n;
    while(n--){
        cin >> a;
        num[a]=1;
    }

    bool t=false;

    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++)
            sum+=num[mat[i][j]];
        if(sum==3)
            t=true;
    }
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++)
            sum+=num[mat[j][i]];
        if(sum==3)
            t=true;
    }

    if(num[mat[0][0]]+num[mat[1][1]]+num[mat[2][2]]==3)
        t=true;
    if(num[mat[0][2]]+num[mat[1][1]]+num[mat[2][0]]==3)
        t=true;

    if(t)
        cout << "Yes\n";
    else
        cout << "No\n";
    
    return 0;
}