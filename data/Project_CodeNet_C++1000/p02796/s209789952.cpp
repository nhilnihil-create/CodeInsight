 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;

 int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> l(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> l[i];     
    }
    vector<pair<int,int>> sc(n);
    for(int i=0;i<n;i++){
        sc[i].second = max(0,x[i]-l[i]);
        sc[i].first = x[i]+l[i];
    }
    sort(sc.begin(),sc.end());
    int cnt=0;
    int endtime = 0;
    for(int i=0;i<n;i++){
        if(endtime<=sc[i].second){
            cnt++;
            endtime = sc[i].first;
        }
    }
    cout << cnt << endl;
    return 0;
 }