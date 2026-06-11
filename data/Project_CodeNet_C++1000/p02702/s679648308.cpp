#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=1'000'000'007;
const double EPS=1e-14;
const bool DEBUG=false;

const string YES = "YES";
const string NO = "NO";
const string Yes = "Yes";
const string No = "No";

template<class T>
void debug(T head){
    if(DEBUG){
        cout<<head<<endl;
    }
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cout<<head<<" ";
        debug(body...);
    }
}

/////

void answer(){
    string S;
    cin>>S;

    vector<long> mod_2019(S.length());
    long pow10 = 1;
    long number = 0;
    for(int i=S.length()-1; i>=0; i--){
        number = number + pow10 * (S[i] - '0');
        number %= 2019;
        mod_2019[i] = number;
        pow10 = pow10 * 10 % 2019;
    }

    vector<long> count(2019, 0);
    for(int i=0; i<S.length(); i++){
        count[mod_2019[i]]++;
        debug(i, mod_2019[i], count[mod_2019[i]]);
    }

    long ans = 0;
    for(int i=0; i<count.size(); i++){
        ans += count[i] * (count[i] - 1) / 2;
    }
    ans += count[0];

    cout<<ans<<endl;

    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    answer();

    return 0;
}
