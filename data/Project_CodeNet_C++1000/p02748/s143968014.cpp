 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 using v = vector<int>;
 const int INF = 2147483647;
    //int nax = max_element(p.begin(),p.end())-p.begin();
    //int nin = max_element(p.begin(),p.end())-p.begin();
     //sort(l.begin(),l.end(),greater<int>());
     //stringは",charは'
     //ちょっとあやしかったら立ち止まって考える
     //例外処理はreturn忘れずに
     //文字列連結 文字+="aa" でできる

 int main(){
     int a,b,m;
     cin >> a >> b >> m;
     v va(a);
     v vb(b);
     rep(i,a) cin >> va[i];
     rep(i,b) cin >> vb[i];
     v x(m);
     v y(m);
     v c(m);
     rep(i,m) {
         cin >> x[i] >> y[i] >> c[i];
     }
     int nin = INF;
     rep(i,m){
        //  nin = min(nin,va[x[i]-1]+vb[y[i]-1]-c[i]);
         nin = min(nin,va[x[i]-1]+vb[y[i]-1]-c[i]);

     }
     sort(va.begin(),va.end());
     sort(vb.begin(),vb.end());
    nin = min(nin,va[0]+vb[0]);
     cout << nin << endl;
     return 0;
 }