#include <iostream>
#include <string>

int main()
{
    while(1)
    {
        std::string ostr = "";
        std::string current = "";

        std::cin >> ostr;

        if (ostr == "-") {
            break;
        }

        int n = 0;

        std::cin >> n;

        int shuffle[n] = {};

        for (int i = 0; i < n; i++) {
            std::cin >> shuffle[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = shuffle[i]; j < ostr.length(); j++) {
                current += ostr[j];
            }

            for (int j = 0; j < shuffle[i]; j++) {
                current += ostr[j];
            }
            ostr = current;
            current = "";
        }


        std::cout << ostr << std::endl;


    }

    return 0;

}