#include <bits/stdc++.h>
using namespace std;

void Main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        vector<int> p1(n), p2(n+1);
        for (int j = 0; j < n; j++)
        {
            p1[max(0, j - a[j])] += 1;
            p2[min(j + a[j] + 1, n)] += 1;            
        }
        for (int j = 1; j < n; j++)
        {
            p1[j] = p1[j-1] + p1[j];
            p2[j] = p2[j-1] + p2[j];            
        }
        for (int j = 0; j < n; j++)
        {
            a[j] = p1[j] - p2[j];
        }
        
        int finish = 1;
        for (int i = 0; i < n; i++)
        {
            if(a[i] < n) finish = 0;
        }
        if(finish){
            break;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
