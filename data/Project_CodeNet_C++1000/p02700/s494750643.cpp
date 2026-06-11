#include <iostream>
using namespace std;
int main()
{
  
  int a,b,c,d;
  std::cin >> a >> b >> c >> d;

    
  for(int i=1;1>0;i++){
        if(b*i>=c){
            cout << "Yes" << endl;
            return 0;
        }
        else if(d*i>=a){
            cout << "No" << endl;
            return 0;
        }
    }
}
