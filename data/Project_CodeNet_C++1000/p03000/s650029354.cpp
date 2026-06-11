#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main()
{
    int N,X,count=0,y=0;
    cin >> N >> X;
    int L[100];
    for(int i =0; i < N; i++)
    {
        cin >> L[i];
    }
    while(y<=X)
    {
        y+=L[count];
        count++;
    }
    cout << count;
}
