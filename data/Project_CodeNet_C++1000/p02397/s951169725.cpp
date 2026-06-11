#include <iostream>
using namespace std;

int main(){
        int x,y;
        while(cin>>x>>y&&(x||y)){
                bool f = (x<y);
                cout<<(f?x:y)<<" "<<(f?y:x)<<endl;
        }
        return 0;
}