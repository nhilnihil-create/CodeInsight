 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 using v_i = vector<int>;
 using v_s = vector<string>;
 const int INF = 2147483647;

 int main(){
     int n;
     cin >> n;
     v_s s(n);
     v_i t(n);
     int sum =0;
     rep(i,n){
         cin >> s[i];
         cin >> t[i];
         sum+=t[i];
     }    
     string x;
     cin >> x;
     int num;
     rep(i,n){
         if(x==s[i])
            num = i;
     }
     int sum2 =0;
      for(int i=0;i<=num;i++){
          sum2+=t[i];
      }
      cout << sum-sum2 << endl;
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