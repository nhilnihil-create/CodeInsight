 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
    //int nax = max_element(p.begin(),p.end())-p.begin();
    //int nin = max_element(p.begin(),p.end())-p.begin();
     //sort(l.begin(),l.end(),greater<int>());
     //stringは",charは'
     //ちょっとあやしかったら立ち止まって考える

 int main(){
     ll h,w;
     cin >> h >> w;
     if(h==1||w==1){
         cout << 1 << endl;
         return 0;
     }
     cout << h*w/2+(h*w)%2 << endl;
     return 0;
 }