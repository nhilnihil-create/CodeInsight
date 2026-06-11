#include <bits/stdc++.h>

#define int long long
#define f first

#define s second
using namespace std;

template<typename T> using vc = vector<T>;
using pii=pair<int, int>;

void xmax(int & a, int b){
    a=max(a, b);
}
void xmin(int& a, int b){
    a=min(a, b);
}

void print(vc <int> & a, string s){
    cerr << s << " : ";
    for (int i=0; i<a.size(); i++){
        cerr <<a[i] << " ";
    }
    cerr << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL_RUN
    freopen("input.txt", "r", stdin);
    int ttt;
    cin >> ttt;
    while(ttt--){
    #endif // LOCAL_RUN
    int k, q;
    cin >> k >> q;
    vc <int> d (k);
    for (int i=0; i<k; i++){
        cin>> d[i];
    }
    for (int t =0 ; t<q; t++){
        int n, x, m;
        cin >> n >> x >> m;
        n--;
        vc <int> sum (k+1);
        for (int i=0; i<k; i++){
            if (d[i]%m == 0){
                sum[i+1]=sum[i]+m;
            }else{
                sum[i+1] = sum[i]+(d[i]%m);
            }
        }
        //print(sum, "sum");
        //cout << sum.back() << " sum back " << " anz ganz" << n/k << " mod " << n%k << " " << sum[n%k] << endl;
        int end_sum =x%m+(n/k)*sum.back() + sum[n%k];
        int res = n - end_sum/m;
        cout << res << "\n";
    }


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
}
