#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int n, count=1, j=0;
    double m;
    std::vector<double> A(10, 0);
    cin >> n;
    while (n!=0)
    {
        int s[n];
        m=0;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            m += s[i];
        }

        m /= (double)n;

        for (int i = 0; i < n; i++)
            A[j] += pow((s[i] - m), 2)/n;
 
        A[j] = sqrt(A[j]);
        cin >> n;
        if (++j==count*10)
        {
            count++;
            A.resize(count*10);
        }
        
    }

    for (int i = 0; i < j; i++)
        cout << std::fixed << std::setprecision(8)
             << A[i] <<endl;

    return 0;
}
