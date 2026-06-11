#include <iostream>

using namespace std;

int main()
{
    int m,d;
    cin>>m>>d;
    int o=0;
    for(int i=22;i<=d;i++){
        if(((i/10)*(i%10))<=m&&(i%10)>=2&&(i/10)>=2){
            o++;
        }

    }
    cout << o << endl;
    return 0;
}
