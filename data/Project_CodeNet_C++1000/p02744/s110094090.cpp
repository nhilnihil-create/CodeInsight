#include <iostream>

using namespace std;
void normal(int len, char limit = 'a', int index = 0, string str = ""){
   
    if(index == len){
        cout<<str<<endl;
        return;
    }
  
    for(char ch = 'a' ;  ch <= limit; ++ch){
        if(ch == limit)
            normal(len, limit+1, index+1, str+ch);
        else
            normal(len, limit, index+1, str+ch);
        
    }  
  
}


int main()
{
    
    int n;
    cin >> n;
    if(n>=0)
    normal(n);

    return 0;
}
