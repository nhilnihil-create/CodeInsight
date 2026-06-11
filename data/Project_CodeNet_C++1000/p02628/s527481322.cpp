#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int main(){
    int N,K;
    cin >> N >> K;
    auto inputs = getValues<int>(N);
    sort(inputs.begin(), inputs.end() );
    int ans = 0;
    rep(i,K){
      ans += inputs.at(i);
    }

    printl(ans);
}
