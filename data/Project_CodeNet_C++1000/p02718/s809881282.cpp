#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)

const ll INF = 10010001010;
const int inf = 1000034000;
typedef vector<ll> vecl;
typedef vector<int> veci;
typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(15);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
     ll vote = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
         vote += A[i];
    }
    int count = 0;
    double D = (double)1 / (4 * M) * vote;
    for (int i = 0; i < N; i++)
    {
        if(D <= A[i]){
            count++;
        }
    }
    if(count >= M){
        cout << "Yes" << endl;
        //cout << count << endl;
    }
    else{
        cout << "No" << endl;
       // cout << count << endl;
    }
}
