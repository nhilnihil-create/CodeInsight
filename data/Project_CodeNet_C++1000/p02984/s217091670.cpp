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

int kaijou(int n){
    if(n==0) return 1;
    else{
        return ((n%MOD)*(kaijou(n-1)%MOD))%MOD;
    }
}

bool ispow(int n){
    int rn=sqrt(n);
    if(rn*rn==n) return true;
    else return false;
}

signed main() {
    int n; cin>>n;
    vector<int> dam(n);
    for(int i=0;i<n;i++) cin>>dam[i];

    vector<int> mountain(n,0);

    int sum=accumulate(all(dam),0LL);
    vector<int> twomountain(n,0);
    int other_mountain=0;

    for(int i=0;i<n;i++){
        twomountain[i]=dam[i]*2;
    }

    int i=0;
    while((i)<(n-2)){
        other_mountain+=twomountain[i];
        i+=2;
    }
    int left=0,right=i-2;

    mountain[n-1]=sum-other_mountain;
    for(int i=n-2;i>=0;i--){
        mountain[i]=twomountain[i]-mountain[i+1];
    }
    
    /*
    for(int i=0;i<n;i++){
        //cout<<left<<" "<<right<<endl;
        if(i==0){
            mountain[n-1]=sum-other_mountain;
        }else{
            mountain[left-1]=sum-other_mountain;
        }
        other_mountain-=twomountain[left];
        left+=2;
        right+=2;
        if(left>=n) left%=n;
        if(right>=n) right%=n;
        other_mountain+=twomountain[right];
    }*/

    output_yoko(mountain);
}
