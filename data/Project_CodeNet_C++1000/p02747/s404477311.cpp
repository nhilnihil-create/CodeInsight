 #include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;
typedef long double ld;
typedef vector<int> vr;
typedef pair<int, int> pr;
#define pb push_back
#define ff first
#define ss second
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433
#define endl "\n"
//cout << fixed << setprecision(2);

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int len = s.size();
    int cnt = 0;
    if(len % 2 != 0){
        cout << "No" << endl;
        exit(0);
    }
    for(int i = 0; i < len; i+=2){
        if(s[i] != 'h' || s[i+1] != 'i'){
            //cout << s[i] << " " << s[i+1] << endl;
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
    return 0;
}

