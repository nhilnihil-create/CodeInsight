#include <stdio.h>
#include <iostream>
#include <vector>

//https://atcoder.jp/contests/abc156/tasks/abc156_c

int main()
{
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);               //gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    //linjen er opp til 100. det er en linje p[ lengde hundre med hus p[ bare de nevte stedene]]

    int houses;
    std::cin >> houses;

    std::vector<int> vec(99);

    for (int i = 0; i < houses; i++)
    {
        int houseLocation;
        std::cin >> houseLocation;

        for (int u = 0; u < 99; u++)
        {
            int distStam = (u + 1 - houseLocation) * (u + 1 - houseLocation);
            vec[u] = vec[u] + distStam;
            //std::cout << "   " << vec[u] << "\n";
        }
    }

    int min = vec[0];
    for (int u = 1; u < 99; u++)
    {
        //std::cout << "   " << vec[u] << "\n";
        if (vec[u] < min)
        {
            min = vec[u];
        }
    }
    std::cout << min << "\n";
}
