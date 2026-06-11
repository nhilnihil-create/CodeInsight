// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com

#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'
#define precise(n,k) fixed << setprecision(k) << n
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define uint  unsigned int
#define ll    long long
#define ull   unsigned long long
#define ld    long double

#define pii   pair<int, int>
#define piii  pair<int, pair<int, int>>
#define pll   pair<ll, ll>

#define F  first
#define S  second
#define PB push_back
#define MP make_pair

#define debug(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool b) {
    return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename T>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const T &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string((T)x);
    }
    res += "}";
    return res;
}

// add templates here

template<class T>
void println(const vector<T> &data) {
    cout << to_string<vector<T>, T>(data) <<endl;
}

template<class T>
void println(const T &data) {
    cout << to_string((T)data) << endl;
}

const int MOD = int(1e9+7);
const int oo  = int(1e9 + 20);
const ll lloo  = (ll)(1e18 + 10);

bool isInteger(double number) {
    return number == int(number);
}

double distance(vector<int> &X, vector<int> &Y) {
    double answer = 0.0;
    int n = min(X.size(), Y.size());
    for(int i = 0; i < n; ++i) {
        answer += pow( (X[i] - Y[i]) ,2);
    }
    
    return sqrt(answer);
}

    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, D;
    cin >> N >> D;
    vector<vector<int>> grid(N+1, vector<int>(D+1));
    
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= D; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = i + 1; j <= N; ++j) {
            if(i == j) continue;
            double dist = distance(grid[i], grid[j]);
            if(isInteger(dist)) answer++;
        }
    }
    
    cout << answer << endl;

    return 0;
}