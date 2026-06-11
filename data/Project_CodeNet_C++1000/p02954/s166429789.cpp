#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=1'000'000'007;
const double EPS=1e-14;
const bool DEBUG=true;

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

    S = S + 'R';
    int len = S.length();
    vector<int> answer(len-1, 0);
    int l_count = 0;
    int r_count = 0;
    int r_index = 0;
    int l_index = 0;
    for(int i=0; i<len-1; ++i){
        if(S[i] == 'R'){
            r_count++;
        }
        if(S[i] == 'L'){
            l_count++;
        }
        if(S[i] == 'R' && S[i+1] == 'L'){
            r_index = i;
            l_index = i+1;
        }
        if(S[i] == 'L' && S[i+1] == 'R'){
            answer[r_index] = int(ceil(r_count / 2.0)) + l_count / 2;
            answer[l_index] = int(ceil(l_count / 2.0)) + r_count / 2;
            l_count = 0;
            r_count = 0;
        }
    }

    for(auto x : answer){
        cout<<x<<" ";
    }
    cout<<endl;

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
