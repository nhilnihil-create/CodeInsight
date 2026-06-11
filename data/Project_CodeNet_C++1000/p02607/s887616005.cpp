#include <iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int N, * ai, count = 0;
    cin >> N;
    vector<int>I(N);
   
    for (int i = 0; i < N; ++i)
    {
        I.at(i)=i+1;
    }
    ai = new int[N];
    for (int j = 0; j < N; j++)
    {
        cin >> ai[j];
    }
    for (int k = 0; k < N; k++)
    {
        if (I[k] % 2 != 0 && ai[k] % 2 != 0)
        {
            count++;
        }
    }
    cout << count << endl;

    delete[]ai;
}
