#include <iostream>

using std::cout;
using std::cin;

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    
    int en;
    int ans;
    int set[]={500,100,50,10,5,1};
    
    
    
    
    while(cin>>en&&en!=0)
    {
    en=1000-en;
        
        for (int i=0;i<sizeof(set)/sizeof(set[0]); ++i)
        {
            while(true)
            {
                if(set[i]<=en)
                {
                    en-=set[i];
                    ++ans;
                }
                else
                {
                    break;
                }
            }
        }
        cout<< ans <<"\n";
        ans=0;
    }

    
    return 0;
}