#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// int main()
// {
//     vector<vector<vector<ll>>> Lun(12, vector<vector<ll>>(10, vector<ll>(0)));

//     int K;
//     cin >> K;

//     vector<ll> nums(0);

//     for (int i = 0; i < 10; i++)
//     {

//         Lun[0][i].push_back(i);

//         if (i != 0)
//         {
//             nums.push_back(i);
//         }
//     }

//     for (int i = 1; i < 12; i++)
//     {

//         for (int j = 0; j < 10; j++)
//         {

//             if (j > 0)
//             {

//                 for (int k = 0; k < Lun[i - 1][j - 1].size(); k++)
//                 {

//                     ll A = j * pow(10, i) + Lun[i - 1][j - 1][k];

//                     Lun[i][j].push_back(A);

//                     nums.push_back(A);
//                 }
//             }

//             for (int k = 0; k < Lun[i - 1][j].size(); k++)
//             {

//                 ll A = j * pow(10, i) + Lun[i - 1][j][k];

//                 Lun[i][j].push_back(A);

//                 if (j != 0)
//                 {

//                     nums.push_back(A);
//                 }
//             }

//             if (j < 9)
//             {

//                 for (int k = 0; k < Lun[i - 1][j + 1].size(); k++)
//                 {

//                     ll A = j * pow(10, i) + Lun[i - 1][j + 1][k];

//                     Lun[i][j].push_back(A);

//                     if (j != 0)
//                     {
//                         nums.push_back(A);
//                     }
//                 }
//             }
//         }
//     }

//     sort(nums.begin(),nums.end());

//     cout << nums[K-1] << endl;

//     return 0;
// }

int main()
{

    int K;
    cin >> K;

    queue<ll> A;


    int count = 0;


    for(int i=1; i<10;i++){

        A.push(i);
        count++;
        if(count==K){


            cout << A.back() << endl;


            return 0;
        }
    }

    
    while (count < K)
    {
        ll a = A.front();

        A.pop();

        if (a % 10 != 0)
        {

            A.push(a * 10 + a % 10 - 1);
            count++;
            if (count == K)
            {

                break;
            }
        }
        A.push(a * 10 + a % 10);

        count++;
        if (count == K)
        {

            break;
        }

        if (a % 10 != 9)
        {

            A.push(a * 10 + a % 10 + 1);

            count++;
            if (count == K)
            {

                break;
            }
        }
    }


    cout << A.back() << endl;

    return 0;
}