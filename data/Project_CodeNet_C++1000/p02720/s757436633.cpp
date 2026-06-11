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
    int k; cin>>k;

    queue<int> q;
    for(int i=1;i<10;i++) q.push(i);

    int cnt=0;

    while(cnt<k){
        cnt++;
        int top=q.front();
        q.pop();
        //cout<<top<<endl;

        if(cnt==k){
            cout<<top<<endl;
            break;
        }

        if(top%10!=0){
            q.push(top*10+top%10-1);
        }
        q.push(top*10+top%10);
        if(top%10!=9){
            q.push(top*10+top%10+1);
        }
    }
}
