#include <stdio.h>
// two strings S and T. consisting of lowercase English letters. Concatenate T and S in this order, without space in between, and print the resulting string.
// S and T are strings consisting of lowercase English letters.
// The lengths of S and T are between 1 and 100 (inclusive).

int main() {
    char firstWord[102]; // this means 100 characters
    char secondWord[102]; // this means 100 characters
    scanf("%s %s", secondWord, firstWord);
    printf("%s%s", firstWord, secondWord);

    return 0;
}