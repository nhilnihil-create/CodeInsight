#include <iostream>

using namespace std;

int main()
{
    int h1, m1, h2, m2, k;
    cin>>h1>>m1>>h2>>m2>>k;

    int wakeTime = h2 - h1;
    wakeTime *= 60;
    wakeTime += (m2-m1);

    int study = wakeTime - k;
    cout<<study<<endl;

    return 0;
}
