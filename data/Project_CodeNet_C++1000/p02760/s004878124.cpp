#include <stdio.h>
#include <iostream>
#include <vector>

//https://atcoder.jp/contests/abc157/tasks/abc157_b

int main()
{
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);               //gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    //linjen er opp til 100. det er en linje p[ lengde hundre med hus p[ bare de nevte stedene]]

    std::vector<int> vecBool(9);
    std::vector<int> vec(9);
    for (int u = 0; u < 9; u++)
    {
        std::cin >> vec[u];
        vecBool[u] = 0;
    }

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        //ma enten ha en hashmap eller lagre en ekstra med en og nuller
        int newNumber;
        std::cin >> newNumber;
        for (int u = 0; u < 9; u++)
        {
            if (vec[u] == newNumber)
            {
                vecBool[u] = 1;
            }
        }
    }

    //egen case for midterste
    if (vecBool[4] == 1)
    {

        int before = vecBool[4 - 4];
        int after = vecBool[4 + 4];

        if (after + before == 2)
        {
            std::cout << "Yes\n";
            return (0);
        }

        before = vecBool[4 - 2];
        after = vecBool[4 + 2];

        if (after + before == 2)
        {
            std::cout << "Yes\n";
            return (0);
        }
    }

    //ROW DOWN
    for (int u = 1; u < 9; u += 3)
    {
        int current = vecBool[u];
        if (current == 1)
        {
            if (vecBool[u - 1] + vecBool[u + 1] == 2)
            {
                std::cout << "Yes\n";
                return (0);
            }
        }
    }

    //row horizontal
    for (int u = 3; u <= 6; u++)
    {
        int current = vecBool[u];
        if (current == 1)
        {
            if (vecBool[u - 3] + vecBool[u + 3] == 2)
            {
                std::cout << "Yes\n";
                return (0);
            }
        }
    }

    // for (int u = 0; u < 9; u++)
    // {
    //     int current = vecBool[u];
    //     if (current == 1)
    //     {
    //         for (int offset = 1; offset < 4; offset += 2)
    //         {
    //             std::cout << offset << "----\n";
    //             int before = 0;
    //             int after = 0;
    //             if (u - offset >= 0)
    //             {
    //                 before = vecBool[u - offset];
    //             }
    //             if (u + offset <= 8)
    //             {
    //                 after = vecBool[u + offset];
    //             }

    //             if (after + before == 2)
    //             {
    //                 std::cout << "Yes\n";
    //                 return (0);
    //             }
    //         }
    //     }
    // }

    //sjekke +- 1,2,3 og 4  hvis de eksisterer for alle.

    std::cout << "No\n";
}
