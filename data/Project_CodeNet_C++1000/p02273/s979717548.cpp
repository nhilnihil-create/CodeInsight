#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define double long double
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output(vector<string> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if(i!=0) cout<<" ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void koch(int d,pair<double,double> p1,pair<double,double> p2){

    if(d==0){
        cout<<p1.first<<" "<<p1.second<<endl;
        if(p2.first==100.0 && p2.second==0) cout<<p2.first<<" "<<p2.second<<endl;
    }
    else{
        pair<double,double> s,t,u;
        s=make_pair((p1.first*2.0+p2.first)/3.0,(p1.second*2.0+p2.second)/3.0);
        t=make_pair((p1.first+p2.first*2.0)/3.0,(p1.second+p2.second*2.0)/3.0);

        double ux=s.first+(t.first-s.first)*cos(pi/3.0)-(t.second-s.second)*sin(pi/3.0);
        double uy=s.second+(t.first-s.first)*sin(pi/3.0)+(t.second-s.second)*cos(pi/3.0);
        u=make_pair(ux,uy);
        //cout<<u.first<<" "<<u.second<<endl;     

        koch(d-1,p1,s);
        koch(d-1,s,u);
        koch(d-1,u,t);
        koch(d-1,t,p2);
    }
}

signed main(){
    int n; cin>>n;
    cout<<fixed<<setprecision(8);
    koch(n,make_pair(0,0),make_pair(100,0));
}
