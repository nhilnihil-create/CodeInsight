#include <cstdio>
using namespace std;

int main() {
    int num_of_entries;

    scanf("%d", &num_of_entries);

    for (int i = 0; i < num_of_entries; i++) {
        int entry;
        scanf("%d", &entry);

        if (entry % 2 == 0) {
            if (entry % 3 != 0 && entry % 5 != 0) {
                printf("DENIED\n");
                return 0;
            }
        }
    }

    printf("APPROVED\n");
}