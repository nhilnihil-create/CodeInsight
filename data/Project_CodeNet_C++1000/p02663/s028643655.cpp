#include <iostream>

using namespace std;

int main()
{

    int H1,M1,H2,M2,k;
    int defH , defM ;
    cin>>H1>>M1>>H2>>M2>>k;


        defH=H2-H1;
        defM=M2-M1;

        cout<<((defH*60)+defM) -k;


    return 0;
}
