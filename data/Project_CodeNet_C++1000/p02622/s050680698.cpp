#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int counter =0;
    string m , n ;
    cin>>m>>n;
    for(int i =0 ; i< m.length() ; i++){
            if(m[i] != n[i]){
                counter++;
            }


    }
   cout<<counter;
return 0;
}
