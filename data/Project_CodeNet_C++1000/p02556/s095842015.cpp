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

void answer(){
    int N;
    cin>>N;

    vector<long> x(N), y(N), z(N), w(N);
    for(int i=0; i<N; ++i){
        cin>>x[i]>>y[i];
        z[i] = x[i] + y[i];
        w[i] = x[i] - y[i];
    }

    auto z_max_itr = max_element(z.begin(), z.end());
    auto z_min_itr = min_element(z.begin(), z.end());
    auto w_max_itr = max_element(w.begin(), w.end());
    auto w_min_itr = min_element(w.begin(), w.end());

    cout<<max(*z_max_itr-*z_min_itr, *w_max_itr-*w_min_itr)<<endl;

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
