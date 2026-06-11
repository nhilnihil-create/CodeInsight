        #include <iostream>
        using namespace std;
        #define pi 3.14159
         
        int main(){
          int N,M;
          cin >> N>>M;
          int ans =0;
          for(int i=0 ;i<M;i++){
         int a;
            cin >> a;
            ans += a;
          }
          ans = (ans-N)*(-1);
         
          if(ans>=0){
          
          cout << ans<<endl;
          }else{
            cout << -1<<endl;
          }
          return 0;  
        }  