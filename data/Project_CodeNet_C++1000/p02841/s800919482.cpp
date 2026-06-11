 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 using v_i = vector<int>;
 using v_s = vector<string>;
 const int INF = 2147483647;

 int main(){
     int m1,d1,m2,d2;
     cin >> m1 >> d1 >> m2 >> d2;
     if(d1+1==d2) cout << 0 << endl;
     else cout << 1 << endl;
     return 0;
 }

     //int nin = *max_element(a.begin(),p.end());
    //int nax = *max_element(a.begin(),p.end())-p.begin();
    //int min_index = min_element(p.begin(),p.end())-p.begin();
     //sort(l.begin(),l.end(),greater<int>());
     //stringは",charは'
     //ちょっとあやしかったら立ち止まって考える
     //例外処理はreturn忘れずに
     //文字列連結 文字+="aa" でできる