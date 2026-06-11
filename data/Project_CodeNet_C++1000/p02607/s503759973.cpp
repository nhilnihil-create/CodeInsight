using namespace std;
#include <bits/stdc++.h>

int main()
{
    int a,count=0;cin>>a;
    int b[a];
    for(int i=1;i<=a;i++){cin>>b[i];
        if(i%2==1){
            if(b[i]%2==1){
                count++;
            }
        }
    }
    std::cout << count << std::endl;
}
