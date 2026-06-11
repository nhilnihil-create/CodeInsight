#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define all(x) x.begin(), x.end()
#define watch(x) cout<<#x<<" : "<<x<<endl
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define testCases int tt;cin>>tt; while(tt--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<string> vs;

int main() {
    fastio;
    string str;
    cin >> str;
    int answer = 0;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        int temp = str[i]-'0';
        answer+=temp;
    }   
    if (answer%9) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    return 0;
}