#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void read(){

}

template<typename First, typename... Rest>
void read(First& first, Rest&... rest){
    cin >> first;
    read(rest...);
}

template<typename T>
void read_vec(vector<T>& v, size_t n){
    for(size_t i = 0; i < n; i++){
        T t;
        cin >> t;
        v.push_back(t);
    }
}

int main(){
    ll a;
    string s;
    read(a, s);
    if(a >= 3200) {
        cout << s;
    }
    else {
        cout << "red";
    }
    return 0;
}