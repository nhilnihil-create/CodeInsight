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
     string s;
     cin >> s;
     bool can = false;
     if(s=="hi") can = true;
     if(s=="hihi") can = true;
     if(s=="hihihi") can = true;
     if(s=="hihihihi") can = true;
     if(s=="hihihihi") can = true;
     if(s=="hihihihihi") can = true;
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
     return 0;
 }