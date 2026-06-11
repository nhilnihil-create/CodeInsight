#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++)
    {
        cin >> A.at(i);
    }
    int count=0;
    int min=10000;
    int sum1=0;
    int sum2=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<count; j++)
        {
            sum1+=A.at(j);
        }
        for(int k=count; k<N; k++)
        {
            sum2+=A.at(k);
        }
        if(min>abs(sum1-sum2))
        {
            min=abs(sum1-sum2);
        }
        count++;
        sum1=0;
        sum2=0;
    }
    cout << min << endl;
}
