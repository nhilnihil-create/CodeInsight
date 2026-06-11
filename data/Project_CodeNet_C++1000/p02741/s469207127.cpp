 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
    //int nax = max_element(p.begin(),p.end())-p.begin();
    //int nin = max_element(p.begin(),p.end())-p.begin();
     //sort(l.begin(),l.end(),greater<int>());
     //stringは",charは'
     //ちょっとあやしかったら立ち止まって考える
     //例外処理はreturn忘れずに

 int main(){
     vector<int> a = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
     int k;
     cin >> k;
     rep(i,k){
         if(i==k-1){
         cout << a[i] << endl;;
         break;
         }
     }
     return 0;
 }