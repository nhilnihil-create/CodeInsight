 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 using v_i = vector<int>;
 using v_ll = vector<ll>;
 using v_s = vector<string>;
 const int INF = 2147483647;

 int main(){
     int n;
     cin >> n;
     deque<int> dq;
     rep(i,n){ 
         ll input;
         cin >> input;
         dq.push_back(input);
     }
     ll a=0;
     ll b=0;
     while(!dq.empty()){
        if(a<=b) {
            ll now = dq.front();
            dq.pop_front();
            a+=now;
        }
        else{
            ll now = dq.back();
            dq.pop_back();
            b+=now;
        } 
     }
     cout << abs(a-b) << endl;
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