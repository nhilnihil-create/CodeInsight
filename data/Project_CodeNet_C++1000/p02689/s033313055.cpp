#include <iostream>
#include<set>
using namespace std;
int main(void){
    // Your code here!
    int n,m;
    set<int>s;
    cin>>n>>m;

    int H[n];
    for(int i=0;i<n;i++)
      {
          cin>>H[i];
          s.insert(i+1);
      }
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(H[a-1] < H[b-1]){
            s.erase(a);
        }else if(H[a-1] > H[b-1]){
            s.erase(b);
        }else{
                s.erase(a);
                s.erase(b);
        }    
    }
    
    cout<<s.size();
}
