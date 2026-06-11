#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i,n) for(int i=0; i<n; i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
typedef map<int,int> mp;

const int MOD = 1e9 + 7;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d;
    cin >> s;

    bool f = true;

    FOR(i, b, d-1){
        if(s[i] == '#' && s[i+1] == '#'){
            f = false;
            break;
        }
    }

    FOR(i, a, c-1){
        if(s[i] == '#' && s[i+1] == '#'){
            f = false;
            break;
        }
    }

    if(c > d){
        FOR(i, b-1, d){
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
                f = true;
                break;
            }else{
                f = false;
            }
        }
    }


    cout << (f ? "Yes" : "No") << endl;

    return 0;
}

