#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T>
vector<T> divisor(T n){
    vector<T> res;
    for(T i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            T j = n / i;
            if(i != j)res.push_back(j);
        }
    }
    return res;
}

const int MAX = 1000000;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> in(MAX + 1);
    for(int i = 0; i < n; i++)cin >> a[i], in[a[i]]++;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        vector<int> num = divisor(a[i]);
        int res = 0;
        for(int j = 0; j < num.size(); j++) {
            res += in[num[j]];
        }
        if(res == 1)sum++;
    }
    cout << sum << '\n';
}
