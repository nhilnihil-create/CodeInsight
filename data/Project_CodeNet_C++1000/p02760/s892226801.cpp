#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int N;
vector<vector<int> > A(3, vector<int>(3));
int B;
int main(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            /* code */
            cin >> A.at(i).at(j);
        }
    }
    cin >> N;

    for (int b = 0; b < N; b++)
    {
        /* code */
        cin >> B;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (A.at(i).at(j) == B)
                {
                    A.at(i).at(j) = 0;
                }
                
            }
        }
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << A.at(i).at(j) << endl;
    //     }
    // }

    // int x = 0;
    for (int i = 0; i < 3; i++)
    {
        if (A.at(i).at(0) == A.at(i).at(1) &&  A.at(i).at(0) == A.at(i).at(2))
        {
            printf("%s", "Yes");
            return 0;
        }
        else if (A.at(0).at(i) == A.at(1).at(i) && A.at(0).at(i) ==  A.at(2).at(i))
        {
            printf("%s", "Yes");
            return 0;
        }
    }

    if (A.at(0).at(0) == A.at(1).at(1) && A.at(0).at(0) == A.at(2).at(2))
    {
        printf("%s", "Yes");
        return 0;
    }
    else if (A.at(0).at(2) == A.at(1).at(1) && A.at(0).at(2) == A.at(2).at(0))
    {
        printf("%s", "Yes");
        return 0;
    }
    else{
        printf("%s", "No");
        return 0;
    }


}