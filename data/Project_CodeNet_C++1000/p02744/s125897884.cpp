#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int N;

    cin >> N;

    queue<string> A;

    A.push("a");

    if (N == 1)
    {

        cout << 'a' << endl;
        return 0;
    }

    while (1)
    {

        string s = A.front();

        if (s.size() == N)
        {
            break;
        }

        A.pop();

        char c = s.back();

        char d = c + 1;



        char largest = 'a';


        for(int i=0;i<s.size();i++){

            largest = max(largest,s[i]);
        }

        for (char k = 'a'; k <= largest+1; k++)
        {

            string f = s + k;

            A.push(f);

            if (f.size() == N)
            {

                cout << f << endl;
            }
        }

       
    }

    return 0;
}
