#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output_tate(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output_yoko(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}
int MOD = pow(10, 9) + 7;

//出力形式を返す関数
string out(vector<int> v){
    string ans="[";
    for(int i=0;i<v.size();i++){
        if(i!=0) ans+=", ";
        ans+=to_string(v[i]);
    }
    ans+="]";
    return ans;
}

signed main() {
	int h,n; cin>>h>>n;
    vector<int> dp(h+1,pow(10,9)); dp[0]=0;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];

    //各HPについての処理
    for(int hi=0;hi<h;hi++){
        //各魔法についての処理
        for(int ni=0;ni<n;ni++){
            //hを超える場合はhでいい
            int index=hi+a[ni];
            if(index>h) index=h;
            //dpの値を更新する。いけない体力のところは初期値のまま
            dp[index]=min(dp[index],dp[hi]+b[ni]); 
        }
    }

    cout<<dp[h]<<endl;

}