#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;
const ll mod=1000000007;

int main() {
  int n;
  cin >> n;
  r(a,1){
    if(n==1)cout<<"a"<<endl;
    else r(b,2){
      if(n==2)cout<<"a"<<char('a'+b)<<endl;
      else r(c,max(a,b)+2){
        if(n==3)cout<<"a"<<char('a'+b)<<char('a'+c)<<endl;
        else r(d,max(a,max(b,c))+2){
         if(n==4) cout<<"a"<<char('a'+b)<<char('a'+c)<<char('a'+d)<<endl;
          else r(e,max(a,max(b,max(c,d)))+2){
            if(n==5) cout<<"a"<<char('a'+b)<<char('a'+c)<<char('a'+d)<<char('a'+e)<<endl;
            else r(f,max(a,max(b,max(c,max(d,e))))+2){
              if(n==6) cout<<"a"<<char('a'+b)<<char('a'+c)<<char('a'+d)<<char('a'+e)<<char('a'+f)<<endl;
              else r(g,max(a,max(b,max(c,max(d,max(e,f)))))+2){
                if(n==7) cout<<"a"<<char('a'+b)<<char('a'+c)<<char('a'+d)<<char('a'+e)<<char('a'+f)<<char('a'+g)<<endl;
                else r(h,max(a,max(b,max(c,max(d,max(e,max(f,g))))))+2){
                  if(n==8)cout<<"a"<<char('a'+b)<<char('a'+c)<<char('a'+d)<<char('a'+e)<<char('a'+f)<<char('a'+g)<<char('a'+h)<<endl;
                  else r(i,max(a,max(b,max(c,max(d,max(e,max(f,max(g,h)))))))+2){
                    if(n==9)cout<<"a"<<char('a'+b)<<char('a'+c)<<char('a'+d)<<char('a'+e)<<char('a'+f)<<char('a'+g)<<char('a'+h)<<char('a'+i)<<endl;
                    else r(j,max(a,max(b,max(c,max(d,max(e,max(f,max(g,max(h,i))))))))+2){
                      if(n==10)cout<<"a"<<char('a'+b)<<char('a'+c)<<char('a'+d)<<char('a'+e)<<char('a'+f)<<char('a'+g)<<char('a'+h)<<char('a'+i)<<char('a'+j)<<endl;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
