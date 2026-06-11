#include<bits/stdc++.h>

using namespace std;


#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)for(auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); blockTime.second;debug("%s: %.5lf s\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()/1000.0), blockTime.second = false)

template <typename T>std::string NumberToString ( T Number ){std::ostringstream ss; ss << Number;return ss.str(); } // Usages NumberToString(3)
template <typename T>T StringToNumber ( const string &Text ){istringstream ss(Text);T result;return ss >> result ? result : 0;} // StringToNumber<int>("3")

string StrCpy(string str, long long int start, long long int end){string temp = "";for(long long int i=start; i<=end; i++){temp += str[i];}return temp;}

#define ull unsigned long long int
#define ll long long int
#define gcd(a, b)  __gcd(a, b)
#define lcm(a, b)  ((a*b)/gcd(a, b))

ll row[200009];

int solve(){

    ll n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> row[i];
    }

    ll cnt  = 0;
    ll max = row[0];

    for(int i=1; i<n; i++){

        if(row[i] < max){
            cnt += max - row[i];
        }
        else max = row[i];

    }

    cout << cnt << endl;




    return 0;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("english.txt","r",stdin);

    time__("programm time"){
        solve();
	}
    return 0;

}
